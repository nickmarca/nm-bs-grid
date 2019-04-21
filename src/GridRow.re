module Styles = {
  open Css;

  let container = style([display(flexBox), backgroundColor(hex("ccc"))]);
};

[@react.component]
let make = (~itemWidth: int) => {
  <div className=Styles.container>
    <GridItem width=itemWidth />
    <GridItem width=itemWidth />
    <GridItem width=itemWidth />
    <GridItem width=itemWidth />
    <GridItem width=itemWidth />
    <GridItem width=itemWidth />
  </div>;
};