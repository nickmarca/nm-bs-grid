module Styles = {
  open Css;

  let container = style([height(vh(100.)), display(flexBox), background(hex("fff"))]);
};

type mediaQueryList = {. "matches": bool};
[@bs.send] external matchMedia: (Dom.window, string) => mediaQueryList = "matchMedia";
[@bs.val] external win: Dom.window = "window";

let i = matchMedia(win, "any query");
Js.log(i##matches);

[@react.component]
let make = () => {
  <div className=Styles.container> <Grid /> </div>;
};
