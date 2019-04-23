module Styles = {
  open Css;

  let container = w =>
    style([
      display(flexBox),
      alignItems(center),
      justifyContent(center),
      width(px(w)),
      border(px(1), solid, hex("000")),
      height(pxFloat(1.2 *. float_of_int(w))),
      backgroundColor(hex("ccc")),
    ]);
};

[@react.component]
let make = (~width: int, ~message: string) => {
  <div className={Styles.container(width)}>
    {ReasonReact.string(message)}
  </div>;
};