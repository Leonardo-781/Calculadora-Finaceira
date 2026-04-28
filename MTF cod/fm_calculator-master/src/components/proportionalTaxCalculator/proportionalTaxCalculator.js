import { calculateTax, newInput, newRadio } from '../../Utils';
import './proportionalTaxCalculator.css';

const ProportionalTaxCalculator = (props) => {  
  const timeType = ["mensal", "bimestral", "trimestral", "semestral", "anual"];


  return (
    <div className={props.type +"-container"}>
      <h1>{props.name}</h1>
      <div id={props.type +"-input-container"}>
        {props.inputs.map((value) => newInput(value, props.type))}
        <div className='radio-btn'>
          <h4>Capitalizacao Taxa</h4>
          {timeType.map((value) => newRadio(value, props.type, "capitalizacaoTaxa"))}
        </div>
        <div className='radio-btn'>
          <h4>Tempo Taxa Proporcional</h4>
          {timeType.map((value) => newRadio(value, props.type, "tempoTaxa"))}
        </div>
      </div>
      <button onClick={() => calculateTax(props.type)}>Calcular</button>
    </div>
  );
}

export default ProportionalTaxCalculator;