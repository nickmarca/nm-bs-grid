[@bs.val] [@bs.scope "window"] external innerWidth: int = "innerWidth";
[@bs.val] [@bs.scope "window"] external addEventListener: (string, unit => unit) => unit = "addEventListener";
[@bs.val] [@bs.scope "window"] external removeEventListener: (string, unit => unit) => unit = "removeEventListener";

let useVW = () => {
  let (vw, setVw) = React.useState(() => innerWidth);

  React.useEffect0(() => {
    let listener = () => setVw(_ => innerWidth);
    addEventListener("resize", listener);
    Some(() => removeEventListener("resize", listener));
  });

  vw;
};
