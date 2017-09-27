const rootElem = document.getElementById('root');

const ColorText = (props) =>
  <p className={props.className}>Hello!</p>;

class ColorCarousel extends React.Component {
  constructor(props) {
    super(props);
    this.state = { className: 'blue' };
  }
  
  componentDidMount() {
    this.timerId = setInterval(() => this.nextColor(), 1000);
  }
  
  componentWillUnmount() {
    clearInterval(this.timerId);
  }
  
  nextColor() {
    const newClassName =
      { 'blue':  'red',
        'red':   'green',
        'green': 'blue' }[this.state.className];
    this.setState({ className: newClassName });
  }
  
  render() {
    return <ColorText className={this.state.className} />;
  }
}

ReactDOM.render(<ColorCarousel />, rootElem);
