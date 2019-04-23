module Styles = {
  open Css;

  let container =
    style([display(flexBox), backgroundColor(hex("f5f5f5"))]);
};

[@react.component]
let make = (~children) => {
  <div className=Styles.container> children </div>;
};