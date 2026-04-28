export const newInput = (id, type) => {
    id = String(id)
    const name = id[0].toUpperCase() + id.substring(1);
  
    if(type) id = type + "_" + id;
    
    return(
      <div className= {type + "-data-input"}>
        <label for={id}>{name}</label>
        <input type='number' id={id}></input>
      </div>
    )
}

export const newRadio = (id, type, nameRadio) => {
  id = String(id);
  const name = id[0].toUpperCase() + id.substring(1);
  const originalId = id;

  if(type) id = type + "_" + id;
  
  return(
    <div>
      <label htmlFor={id}>{name}</label>
      <input type='radio' name={nameRadio} id={nameRadio+"_" + originalId} value={originalId}></input>
    </div>
  )
}

export const calculateInterest = (type) => {
  const inputs = document.querySelectorAll(`input[id^="${type}"]`);
  const values = Array.from(inputs, inputs => Number(inputs.value));

  const capital = values[0];
  const montante = values[1];
  const juros = values[2];
  const taxa = values[3];
  const tempo = values[4];

  if(type === "simples"){
    if(!capital) inputs[0].value = Number(juros / (taxa * tempo)).toFixed(2); 
  
    if(!juros) inputs[2].value = Number(capital * taxa * tempo).toFixed(2); 
    
    if(!taxa) inputs[3].value = Number(juros / (capital * tempo)).toFixed(6); 
    
    if(!tempo) inputs[4].value = Number(juros / (capital * taxa)).toFixed(2); 
    
    if(!montante) inputs[1].value = Number(Number(inputs[0].value) + Number(inputs[2].value)).toFixed(2);
  }
  else if (type === "composto"){
    if(!capital) inputs[0].value = Number(juros / (taxa * tempo)).toFixed(2); 
  
    if(!juros) inputs[2].value = Number(capital * (Math.pow((1 + taxa), tempo) -1)).toFixed(2); 
    
    if(!taxa) inputs[3].value = Number( Math.pow((montante / capital), (1/tempo)) - 1).toFixed(6); 
    
    if(!tempo) inputs[4].value = Number((Math.log((montante / capital))) / (Math.log(1+taxa))).toFixed(6); 
    
    if(!montante) inputs[1].value = Number(Number(inputs[0].value) + Number(inputs[2].value)).toFixed(2);
  }
}

export const calculateTax = (type) => {
  const inputs = document.querySelectorAll(`input[id^="${type}"]`);
  const values = Array.from(inputs, inputs => Number(inputs.value));

  if(type === "taxa-efetiva"){
    const taxaEfetiva = values[0];
    const tempo = values[1];
    const taxa = values[2];

    if(!taxaEfetiva) inputs[0].value = (taxa / (1 - (taxa * tempo))).toFixed(6); 

    if(!taxa) inputs[2].value = (taxaEfetiva / (1 + (taxaEfetiva * tempo))).toFixed(6); 
  } 
  else if(type === "taxa-proporcional"){
    const taxaProporcional = values[1];
    const capitalizacao = document.querySelector('input[name="capitalizacaoTaxa"]:checked').value;
    const tempoTaxaProporcional = document.querySelector('input[name="tempoTaxa"]:checked').value;

    if(capitalizacao === tempoTaxaProporcional) inputs[0].value = taxaProporcional;

    if(tempoTaxaProporcional === "anual"){
      if(capitalizacao === "mensal") inputs[0].value = (taxaProporcional / 12).toFixed(6);

      if(capitalizacao === "bimestral") inputs[0].value = (taxaProporcional / 6).toFixed(6);
      
      if(capitalizacao === "trimestral") inputs[0].value = (taxaProporcional / 4).toFixed(6);

      if(capitalizacao === "semestral") inputs[0].value = (taxaProporcional / 2).toFixed(6);
    }
    else if(tempoTaxaProporcional === "semestral"){
      if(capitalizacao === "mensal") inputs[0].value = (taxaProporcional / 6).toFixed(6);

      if(capitalizacao === "bimestral") inputs[0].value = (taxaProporcional / 3).toFixed(6);

      if(capitalizacao === "trimestral") inputs[0].value = (taxaProporcional / 2).toFixed(6);
    }
    else if(tempoTaxaProporcional === "trimestral"){
      if(capitalizacao === "mensal") inputs[0].value = (taxaProporcional / 3).toFixed(6);

      if(capitalizacao === "bimestral") inputs[0].value = (taxaProporcional / (2/3) ).toFixed(6);
    }
    else if(tempoTaxaProporcional === "bimestral"){
      if(capitalizacao === "mensal") inputs[0].value = (taxaProporcional / 2).toFixed(6);
    }
  }
}

export const calculateAmortization = (type, tableID) => {
  const inputs = document.querySelectorAll(`input[id^="${type}"]`);
  const values = Array.from(inputs, inputs => Number(inputs.value));

  const financiamento = values[0];
  const taxa = values[1];
  const tempo = values[2];
  let saldoDevedor = financiamento;
 
  const table = document.getElementById(tableID);
  table.innerHTML = '';
  const firstRow = table.insertRow(-1);

  const firstRowValues = ["Meses", "SD(R$)", "Amort(R$)", "Juros", "PMT(R$)"];

  firstRowValues.map((value) => {
    const newCell = firstRow.insertCell(-1);
    const newText = document.createTextNode(value);
    newCell.appendChild(newText);
  })

  for(let i=0; i <= tempo; i++){
    const newRow = table.insertRow(-1);

    const timeCell = newRow.insertCell(-1);
    const debtCell = newRow.insertCell(-1);
    const amortizationCell = newRow.insertCell(-1);
    const interestCell = newRow.insertCell(-1);
    const installmentCell = newRow.insertCell(-1);

    let amortizationText, interest, installment;
    if(i) amortizationText = document.createTextNode((financiamento / tempo).toFixed(2));
    else amortizationText = document.createTextNode(0.00);
    
    if(i){
      saldoDevedor = saldoDevedor - (financiamento / tempo);
      interest = (saldoDevedor + (financiamento / tempo)) * taxa;
      installment = ((financiamento / tempo) + interest);
    }
    else {
      interest = 0.00;
      installment = 0.00;
    }

    const timeText = document.createTextNode(i);
    const debtText = document.createTextNode(saldoDevedor.toFixed(2));
    const interestText = document.createTextNode(interest.toFixed(2));
    const installmentText = document.createTextNode(installment.toFixed(2));


    timeCell.appendChild(timeText);
    debtCell.appendChild(debtText);
    amortizationCell.appendChild(amortizationText);
    interestCell.appendChild(interestText);
    installmentCell.appendChild(installmentText);
  }
}

export const calculateVPL = (type) => {
  const inputs = document.querySelectorAll(`input[id^="${type}"]`);
  const values = Array.from(inputs, inputs => Number(inputs.value));

  const investimento = values[0];
  const taxa = values[1];
  const tempo = values[2];

  const fluxosDeCaixa = [];

  for(let i=1; i <= tempo; i++){
    const fluxoDeCaixa = Number(prompt("Insira o Fluxo de Caixa do Ano "+ i +":"));
    fluxosDeCaixa.push(fluxoDeCaixa.toFixed(2));
  }

  let somatorioTotal = 0.0, j = 1;


  fluxosDeCaixa.map((value) => { 
    const VPL = value / Math.pow((1+taxa), j);
    somatorioTotal += VPL;
    j++;
  })

  const VPL = (somatorioTotal - investimento).toFixed(2);
  inputs[3].value = VPL;
}