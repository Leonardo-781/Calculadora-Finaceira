import { calculateVPL, newInput } from '../../Utils';
import './VPLCalculator.css';

const VPLCalculator = (props) => {
  const inputValues = ["investimento", "taxa", "tempo", "VPL"];

  return (
    <div className={props.type +"-container"}>
      <h1>{props.name}</h1>
      <div id={props.type +"-input-container"}>
        {inputValues.map((value) => newInput(value, props.type))}
      </div>
      <button onClick={() => calculateVPL(props.type)}>Calcular</button>
    </div>
  );
}

export default VPLCalculator;