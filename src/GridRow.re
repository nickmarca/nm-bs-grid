module Styles = {
  open Css;

  let container = style([display(flexBox), backgroundColor(hex("ccc"))]);
};

[@react.component]
let make = (~children) => {
  <div className=Styles.container> children </div>;
};