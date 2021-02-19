terraform {
  required_version = "~> 0.13.4"
  backend "s3" {
    key     = "terraform-jiawei.tfstate"
    encrypt = true
    region  = "us-west-2"
    bucket  = "o1labs-terraform-state"
    acl     = "bucket-owner-full-control"
  }
}

provider "aws" {
  region = "us-west-2"
}

provider "google" {
  alias   = "google-us-east4"
  project = "o1labs-192920"
  region  = "us-east4"
  zone    = "us-east4-b"
}

variable "mina_image" {
  type = string

  description = "Mina daemon image to use in provisioning a ci-net"
  default     = "gcr.io/o1labs-192920/mina-daemon-baked:0.3.3-coda-to-mina-3eaff9a-jiawei-674e852"
}

variable "mina_archive_image" {
  type = string

  description = "Mina archive node image to use in provisioning a ci-net"
  default     = "gcr.io/o1labs-192920/mina-archive:0.3.3-coda-to-mina-3eaff9a-jiawei-674e852"
}

variable "whale_count" {
  type    = number
  default = 10
}

variable "fish_count" {
  type    = number
  default = 10
}

variable "archive_count" {
  type    = number
  default = 1
}

variable "snark_worker_count" {
  type    = number
  default = 1
}

variable "ci_cluster_region" {
  type    = string
  default = "us-west1"
}

variable "ci_k8s_ctx" {
  type    = string
  default = "gke_o1labs-192920_us-west1_mina-integration-west1"
}

locals {
  seed_region = "us-west1"
  seed_zone = "us-west1-b"
}


module "testnet_east" {
  providers = { google.gke = google.google-us-east4 }
  source    = "../../modules/o1-testnet"

  artifact_path = abspath(path.module)

  # TODO: remove obsolete cluster_name var + cluster region
  cluster_name          = "mina-integration-west1"
  cluster_region        = var.ci_cluster_region
  k8s_context           = var.ci_k8s_ctx
  testnet_name          = "jiawei"

  mina_image            = var.mina_image
  mina_archive_image    = var.mina_archive_image
  mina_agent_image      = "codaprotocol/coda-user-agent:0.1.8"
  mina_bots_image       = "codaprotocol/bots:1.0.0"
  mina_points_image     = "codaprotocol/coda-points-hack:32b.4"

  mina_faucet_amount    = "10000000000"
  mina_faucet_fee       = "100000000"

  agent_min_fee = "0.05"
  agent_max_fee = "0.1"
  agent_min_tx = "0.0015"
  agent_max_tx = "0.0015"
  agent_send_every_mins = "1"

  archive_node_count    = var.archive_count
  mina_archive_schema   = "https://raw.githubusercontent.com/MinaProtocol/mina/develop/src/app/archive/create_schema.sql"

  seed_zone = local.seed_zone
  seed_region = local.seed_region

  log_level              = "Info"
  log_txn_pool_gossip    = false

  block_producer_key_pass = "naughty blue worm"
  block_producer_starting_host_port = 10501

  snark_worker_replicas = var.snark_worker_count
  snark_worker_fee      = "0.025"
  snark_worker_public_key = "B62qk4nuKn2U5kb4dnZiUwXeRNtP1LncekdAKddnd1Ze8cWZnjWpmMU"
  snark_worker_host_port = 10401

  whale_count = var.whale_count
  fish_count = var.fish_count
}
