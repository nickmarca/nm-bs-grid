module Styles = {
  open Css;

  let container =
    style([height(vh(100.)), display(flexBox), background(hex("fff"))]);
};

[@react.component]
let make = () => {
  <div className=Styles.container> <Grid itemWidth=200 /> </div>;
};