[@react.component]
let make = () => {
  let vw = Hooks.useVW();
  let matches = Hooks.useMedia("(min-width: 700px)");

  <div>
    {ReasonReact.string(string_of_int(vw))}
    <br />
    <span> {ReasonReact.string(string_of_bool(matches))} </span>
  </div>;
};
