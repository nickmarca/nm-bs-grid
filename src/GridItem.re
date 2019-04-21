module Styles = {
  open Css;

  let container = w =>
    style([width(px(w)), height(pxFloat(1.2 *. float_of_int(w)))]);
};

[@react.component]
let make = (~width: int) => {
  <div className={Styles.container(width)}>
    {ReasonReact.string("Grid Item")}
  </div>;
};