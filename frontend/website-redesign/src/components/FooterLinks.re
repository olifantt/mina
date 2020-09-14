module Styles = {
  open Css;
  let linksGrid =
    style([
      display(`grid),
      gridTemplateColumns([
        `repeat((`num(2), `minmax((`rem(11.), `rem(11.5))))),
      ]),
      gridColumnGap(`rem(0.5)),
      gridRowGap(`rem(3.1)),
      marginTop(`rem(4.)),
      media(
        Theme.MediaQuery.tablet,
        [
          marginTop(`rem(5.8)),
          gridRowGap(`rem(3.)),
          gridColumnGap(`rem(5.)),
          gridTemplateColumns([
            `repeat((`num(3), `minmax((`rem(11.), `rem(11.5))))),
          ]),
        ],
      ),
      media(
        Theme.MediaQuery.desktop,
        [marginTop(`rem(0.)), width(`rem(36.5)), height(`rem(30.))],
      ),
    ]);
  let linksGroup =
    style([
      display(`flex),
      flexDirection(`column),
      alignContent(`flexStart),
      flexWrap(`wrap),
    ]);
  let linksHeader =
    merge([
      Theme.Type.footerHeaderLink,
      style([
        marginTop(`zero),
        marginBottom(`zero),
        color(white),
        opacity(0.4),
      ]),
    ]);

  let linkStyle =
    merge([
      Theme.Type.sidebarLink,
      style([marginTop(`rem(0.5)), color(white), textDecoration(`none)]),
    ]);
};

// TODO: Add links to footer
[@react.component]
let make = () => {
  <div className=Styles.linksGrid>
    <div className=Styles.linksGroup>
      <h4 className=Styles.linksHeader> {React.string("Get Started")} </h4>
      <Next.Link href="">
        <a className=Styles.linkStyle> {React.string("Documentation")} </a>
      </Next.Link>
      <Next.Link href="">
        <a className=Styles.linkStyle> {React.string("Run a Node")} </a>
      </Next.Link>
      <Next.Link href="">
        <a className=Styles.linkStyle> {React.string("Build on Mina")} </a>
      </Next.Link>
      <Next.Link href="">
        <a className=Styles.linkStyle> {React.string("Join Genesis")} </a>
      </Next.Link>
      <Next.Link href="">
        <a className=Styles.linkStyle> {React.string("Apply for Grants")} </a>
      </Next.Link>
    </div>
    <div className=Styles.linksGroup>
      <h4 className=Styles.linksHeader> {React.string("Resources")} </h4>
      <Next.Link href="">
        <a className=Styles.linkStyle> {React.string("About the Tech")} </a>
      </Next.Link>
      <Next.Link href="">
        <a className=Styles.linkStyle> {React.string("Knowledge Base")} </a>
      </Next.Link>
      <Next.Link href="">
        <a className=Styles.linkStyle> {React.string("Whitepapers")} </a>
      </Next.Link>
      <Next.Link href="">
        <a className=Styles.linkStyle>
          {React.string("Incentive Structure")}
        </a>
      </Next.Link>
      <Next.Link href="">
        <a className=Styles.linkStyle> {React.string("Tokenomics")} </a>
      </Next.Link>
      <Next.Link href="">
        <a className=Styles.linkStyle>
          {React.string("Telemetry Health Dashboard")}
        </a>
      </Next.Link>
    </div>
    <div className=Styles.linksGroup>
      <h4 className=Styles.linksHeader> {React.string("Tools")} </h4>
      <Next.Link href="">
        <a className=Styles.linkStyle> {React.string("Testnet")} </a>
      </Next.Link>
      <Next.Link href="">
        <a className=Styles.linkStyle> {React.string("Block Explorers")} </a>
      </Next.Link>
      <Next.Link href="">
        <a className=Styles.linkStyle>
          {React.string("Node Operator Tools")}
        </a>
      </Next.Link>
      <Next.Link href="">
        <a className=Styles.linkStyle> {React.string("Snarketplace")} </a>
      </Next.Link>
      <Next.Link href="">
        <a className=Styles.linkStyle> {React.string("Network Health")} </a>
      </Next.Link>
      <Next.Link href="">
        <a className=Styles.linkStyle> {React.string("Network Health")} </a>
      </Next.Link>
      <Next.Link href="">
        <a className=Styles.linkStyle>
          {React.string("Snarkers Dashboard")}
        </a>
      </Next.Link>
    </div>
    <div className=Styles.linksGroup>
      <h4 className=Styles.linksHeader> {React.string("Project")} </h4>
      <Next.Link href="">
        <a className=Styles.linkStyle> {React.string("About Mina")} </a>
      </Next.Link>
      <Next.Link href="">
        <a className=Styles.linkStyle> {React.string("Team")} </a>
      </Next.Link>
      <Next.Link href="">
        <a className=Styles.linkStyle> {React.string("Careers")} </a>
      </Next.Link>
      <Next.Link href="">
        <a className=Styles.linkStyle> {React.string("Media")} </a>
      </Next.Link>
      <Next.Link href="">
        <a className=Styles.linkStyle> {React.string("Blog")} </a>
      </Next.Link>
    </div>
    <div className=Styles.linksGroup>
      <h4 className=Styles.linksHeader> {React.string("Community")} </h4>
      <Next.Link href="">
        <a className=Styles.linkStyle> {React.string("Welcome")} </a>
      </Next.Link>
      <Next.Link href="">
        <a className=Styles.linkStyle> {React.string("Genesis Program")} </a>
      </Next.Link>
      <Next.Link href="">
        <a className=Styles.linkStyle> {React.string("Leaderboard")} </a>
      </Next.Link>
      <Next.Link href="">
        <a className=Styles.linkStyle> {React.string("Grant Program")} </a>
      </Next.Link>
      <Next.Link href="">
        <a className=Styles.linkStyle> {React.string("Events")} </a>
      </Next.Link>
    </div>
    <div className=Styles.linksGroup>
      <h4 className=Styles.linksHeader>
        {React.string("Help and Support")}
      </h4>
      <Next.Link href="">
        <a className=Styles.linkStyle> {React.string("Discord")} </a>
      </Next.Link>
      <Next.Link href="">
        <a className=Styles.linkStyle> {React.string("Forums")} </a>
      </Next.Link>
      <Next.Link href="">
        <a className=Styles.linkStyle> {React.string("Github")} </a>
      </Next.Link>
      <Next.Link href="">
        <a className=Styles.linkStyle> {React.string("Wiki")} </a>
      </Next.Link>
      <Next.Link href="">
        <a className=Styles.linkStyle> {React.string("Report a Bug")} </a>
      </Next.Link>
    </div>
  </div>;
};