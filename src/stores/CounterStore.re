type event =
  | Increased
  | Decreased;

type state = {
  count: int
};

let initialState = {
  count: 0
}

let fold = (event: event, state: state) => 
  switch event {
  | Increased =>  { count : state.count + 1 }
  | Decreased =>  { count : state.count - 1 }
};