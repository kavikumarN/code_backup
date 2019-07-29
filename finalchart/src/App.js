import react, { PureComponent } from 'react';
import OHLCChart from './OHLCChart';
import UpStoxLoader from './UpStoxLoader'
import { getStockData } from '../helpers';


export default class App extends PureComponent {

  state = {
    ohlcStockData: {},
  };
  async componentDidMount(){
      const ohlcStockData = await getStockData();
      this.setState({ohlcStockData});
  }

  renderOhlcGraphContainer = () => {
    const {ohlcStockData} = this.state;
    isStockDataLoaded = !ohlcStockData || Object.keys(ohlcStockData).length <1;

    return isStockDataLoaded
      ? this.renderLoadingComponent()
      : this.renderOhlcChartComponent(ohlcStockData);  
  };

  
	renderLoadingComponent = () => {
		return <UpStoxLoader type="Grid" color="#somecolor" height={80} width={80} />;
	};

	renderOhlcChartComponent = ohlcStockData => {
		return <TypeChooser>{type => <OHLCChart type={type} data={ohlcStockData} />}</TypeChooser>;
	};

	render() {
		return this.renderOhlcGraphContainer();
	}
}