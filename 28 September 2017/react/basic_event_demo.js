const rootElem = document.getElementById('root');

class Toggle extends React.Component {
  constructor(props) {
    super(props);

    this.state        = { toggleState: 0 };
    this.clickHandler = this.toggleState.bind(this);
  }
  
  toggleState() {
    this.setState((prevState, props) => {
      const newToggleState = (prevState.toggleState + 1) % 2;
      return { toggleState: newToggleState };
    });
  }
  
  render() {
    return (
      <h1 onClick={this.clickHandler}>
        {this.state.toggleState}
      </h1>);
  }
}

ReactDOM.render(<Toggle />, rootElem);
