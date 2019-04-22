module Styles = {
  open Css;

  let container = style([display(flexBox), flexDirection(column)]);
};

[@react.component]
let make = (~itemWidth: int, ~render) => {
  <div className=Styles.container> {render(itemWidth)} </div>;
};