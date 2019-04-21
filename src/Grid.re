module Styles = {
  open Css;

  let container = style([display(flexBox), flexDirection(column)]);
};

[@react.component]
let make = (~itemWidth: int) => {
  <div className=Styles.container> <GridRow itemWidth /> </div>;
};