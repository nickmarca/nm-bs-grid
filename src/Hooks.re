[@bs.val] [@bs.scope "window"] external innerWidth: int = "innerWidth";
[@bs.val] [@bs.scope "window"] external addEventListener: (string, unit => unit) => unit = "addEventListener";
[@bs.val] [@bs.scope "window"] external removeEventListener: (string, unit => unit) => unit = "removeEventListener";

let useVW = () => {
  let (vw, setVW) = React.useState(() => innerWidth);

  React.useEffect0(() => {
    let listener = () => setVW(_ => innerWidth);
    addEventListener("resize", listener);
    Some(() => removeEventListener("resize", listener));
  });

  vw;
};

type mediaQueryList = {. "matches": bool};
[@bs.send] external matchMedia: (Dom.window, string) => mediaQueryList = "matchMedia";
[@bs.val] external window: Dom.window = "window";

let useMedia = (query: string) => {
  let (matches, setMatches) = React.useState(() => matchMedia(window, query)##matches);

  React.useEffect(() => {
    let listener = () => setMatches(_ => matchMedia(window, query)##matches);
    addEventListener("resize", listener);
    Some(() => removeEventListener("resize", listener));
  });

  matches;
};
