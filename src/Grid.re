[@react.component]
let make = () => {
  let vw = Hooks.useVW();

  <div> {ReasonReact.string(string_of_int(vw))} </div>;
};
