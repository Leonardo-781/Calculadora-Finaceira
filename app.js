const formats = {
  money: (v) => `R$ ${Number(v).toFixed(2)}`,
  num6: (v) => Number(v).toFixed(6),
  pct: (v) => `${(Number(v) * 100).toFixed(2)}%`,
};

const defs = {
  js: {
    select: "js-op",
    fieldsWrap: "js-fields",
    result: "js-result",
    ops: {
      vp: { label: "Calcular Capital (VP)", inputs: ["VF", "i", "n"] },
      vf: { label: "Calcular Montante (VF)", inputs: ["VP", "i", "n"] },
      j: { label: "Calcular Juros (J)", inputs: ["VP", "i", "n"] },
      i: { label: "Calcular Taxa (i)", inputs: ["VP", "VF", "n"] },
      n: { label: "Calcular Tempo (n)", inputs: ["VP", "VF", "i"] },
    },
  },
  jc: {
    select: "jc-op",
    fieldsWrap: "jc-fields",
    result: "jc-result",
    ops: {
      vp: { label: "Calcular Capital (VP)", inputs: ["VF", "i", "n"] },
      vf: { label: "Calcular Montante (VF)", inputs: ["VP", "i", "n"] },
      j: { label: "Calcular Juros (J)", inputs: ["VP", "i", "n"] },
      i: { label: "Calcular Taxa (i)", inputs: ["VP", "VF", "n"] },
      n: { label: "Calcular Tempo (n)", inputs: ["VP", "VF", "i"] },
    },
  },
  dcc: {
    select: "dcc-op",
    fieldsWrap: "dcc-fields",
    result: "dcc-result",
    ops: {
      a: { label: "Calcular Valor Atual (A)", inputs: ["N", "i", "n"] },
      n: { label: "Calcular Valor Nominal (N)", inputs: ["A", "i", "n"] },
      dc: { label: "Calcular Desconto Comercial (Dc)", inputs: ["N", "i", "n"] },
      i: { label: "Calcular Taxa (i)", inputs: ["N", "A", "n"] },
      t: { label: "Calcular Tempo (n)", inputs: ["N", "A", "i"] },
    },
  },
  drc: {
    select: "drc-op",
    fieldsWrap: "drc-fields",
    result: "drc-result",
    ops: {
      a: { label: "Calcular Valor Atual (A)", inputs: ["N", "i", "n"] },
      n: { label: "Calcular Valor Nominal (N)", inputs: ["A", "i", "n"] },
      dr: { label: "Calcular Desconto Racional (Dr)", inputs: ["N", "i", "n"] },
      i: { label: "Calcular Taxa (i)", inputs: ["N", "A", "n"] },
      t: { label: "Calcular Tempo (n)", inputs: ["N", "A", "i"] },
    },
  },
  sac: {
    select: "sac-op",
    fieldsWrap: "sac-fields",
    result: "sac-result",
    ops: {
      pmt: { label: "Calcular PMT", inputs: ["VP", "n", "i", "t"] },
      amort: { label: "Calcular Amortizacao", inputs: ["VP", "n"] },
      j: { label: "Calcular Juros", inputs: ["VP", "n", "i", "t"] },
      sd: { label: "Calcular Saldo Devedor", inputs: ["VP", "n", "t"] },
    },
  },
  te: {
    select: "te-op",
    fieldsWrap: "te-fields",
    result: "te-result",
    ops: {
      mm: { label: "Maior para Menor", inputs: ["n", "ic"] },
      mM: { label: "Menor para Maior", inputs: ["n", "ic"] },
      ef: { label: "Taxa Efetiva (i = ik/k)", inputs: ["ik", "k"] },
    },
  },
};

const inputLabels = {
  VP: "Valor Presente (VP)",
  VF: "Valor Futuro (VF)",
  J: "Juros (J)",
  N: "Valor Nominal (N)",
  A: "Valor Atual (A)",
  Dc: "Desconto Comercial (Dc)",
  Dr: "Desconto Racional (Dr)",
  i: "Taxa unitaria (i)",
  n: "Tempo (n)",
  t: "Numero da prestacao (t)",
  ic: "Taxa conhecida (ic)",
  ik: "Taxa nominal (ik)",
  k: "Periodo (k)",
};

function buildDynamicCalculator(key) {
  const cfg = defs[key];
  const select = document.getElementById(cfg.select);
  const fieldsWrap = document.getElementById(cfg.fieldsWrap);

  Object.entries(cfg.ops).forEach(([opValue, opCfg]) => {
    const option = document.createElement("option");
    option.value = opValue;
    option.textContent = opCfg.label;
    select.appendChild(option);
  });

  const renderFields = () => {
    const opCfg = cfg.ops[select.value];
    fieldsWrap.innerHTML = "";

    opCfg.inputs.forEach((name) => {
      const label = document.createElement("label");
      const input = document.createElement("input");
      input.type = "number";
      input.step = "any";
      input.dataset.name = name;
      label.textContent = inputLabels[name] || name;
      fieldsWrap.appendChild(label);
      fieldsWrap.appendChild(input);
    });
  };

  select.addEventListener("change", renderFields);
  renderFields();
}

function getValuesByWrap(wrapId) {
  const values = {};
  document.querySelectorAll(`#${wrapId} input`).forEach((inp) => {
    values[inp.dataset.name] = Number(inp.value);
  });
  return values;
}

function mustFinite(values) {
  return Object.values(values).every((v) => Number.isFinite(v));
}

function attachActions() {
  document.querySelectorAll("button[data-action]").forEach((btn) => {
    btn.addEventListener("click", () => runCalc(btn.dataset.action));
  });
}

function setResult(id, text, isError = false) {
  const el = document.getElementById(id);
  el.textContent = text;
  el.style.background = isError ? "#fee2e2" : "#e2e8f0";
}

function runCalc(action) {
  try {
    switch (action) {
      case "js":
        calcJurosSimples();
        break;
      case "jc":
        calcJurosCompostos();
        break;
      case "dcc":
        calcDescComercial();
        break;
      case "drc":
        calcDescRacional();
        break;
      case "sac":
        calcSac();
        break;
      case "te":
        calcTaxas();
        break;
      case "fvp":
        calcFvp();
        break;
      case "vpl":
        calcVpl();
        break;
      default:
        break;
    }
  } catch (err) {
    const target = defs[action]?.result || `${action}-result`;
    setResult(target, err.message, true);
  }
}

function positive(name, value) {
  if (!(value > 0)) throw new Error(`${name} deve ser maior que zero.`);
}

function calcJurosSimples() {
  const op = document.getElementById(defs.js.select).value;
  const vals = getValuesByWrap(defs.js.fieldsWrap);
  if (!mustFinite(vals)) throw new Error("Preencha todos os campos numericos.");

  if (op === "i" && vals.n === 0) throw new Error("n nao pode ser zero.");
  if (op === "n" && vals.i === 0) throw new Error("i nao pode ser zero.");
  if ((op === "i" || op === "n") && vals.VP === 0) throw new Error("VP nao pode ser zero.");

  let out;
  if (op === "vp") out = vals.VF / (1 + vals.i * vals.n);
  if (op === "vf") out = vals.VP * (1 + vals.i * vals.n);
  if (op === "j") out = vals.VP * vals.i * vals.n;
  if (op === "i") out = ((vals.VF / vals.VP) - 1) / vals.n;
  if (op === "n") out = ((vals.VF / vals.VP) - 1) / vals.i;

  const label = { vp: "VP", vf: "VF", j: "J", i: "i", n: "n" }[op];
  const text = op === "i"
    ? `${label} = ${formats.num6(out)} (${formats.pct(out)})`
    : op === "n"
      ? `${label} = ${formats.num6(out)}`
      : `${label} = ${formats.money(out)}`;
  setResult(defs.js.result, text, false);
}

function calcJurosCompostos() {
  const op = document.getElementById(defs.jc.select).value;
  const vals = getValuesByWrap(defs.jc.fieldsWrap);
  if (!mustFinite(vals)) throw new Error("Preencha todos os campos numericos.");

  if ((op === "i" || op === "n") && vals.VP === 0) throw new Error("VP nao pode ser zero.");
  if (op === "i" && vals.n === 0) throw new Error("n nao pode ser zero.");
  if (op === "n" && vals.i === -1) throw new Error("i nao pode ser -1.");

  let out;
  if (op === "vp") out = vals.VF / Math.pow(1 + vals.i, vals.n);
  if (op === "vf") out = vals.VP * Math.pow(1 + vals.i, vals.n);
  if (op === "j") out = vals.VP * (Math.pow(1 + vals.i, vals.n) - 1);
  if (op === "i") out = Math.pow(vals.VF / vals.VP, 1 / vals.n) - 1;
  if (op === "n") out = Math.log10(vals.VF / vals.VP) / Math.log10(1 + vals.i);

  const label = { vp: "VP", vf: "VF", j: "J", i: "i", n: "n" }[op];
  const text = op === "i"
    ? `${label} = ${formats.num6(out)} (${formats.pct(out)})`
    : op === "n"
      ? `${label} = ${formats.num6(out)}`
      : `${label} = ${formats.money(out)}`;
  setResult(defs.jc.result, text, false);
}

function calcDescComercial() {
  const op = document.getElementById(defs.dcc.select).value;
  const vals = getValuesByWrap(defs.dcc.fieldsWrap);
  if (!mustFinite(vals)) throw new Error("Preencha todos os campos numericos.");

  if ((op === "i" || op === "t") && vals.N === 0) throw new Error("N nao pode ser zero.");
  if (op === "i" && vals.n === 0) throw new Error("n nao pode ser zero.");
  if ((op === "n" || op === "t") && vals.i === 1) throw new Error("i nao pode ser 1.");

  let out;
  if (op === "a") out = vals.N * Math.pow(1 - vals.i, vals.n);
  if (op === "n") out = vals.A / Math.pow(1 - vals.i, vals.n);
  if (op === "dc") out = vals.N * (1 - Math.pow(1 - vals.i, vals.n));
  if (op === "i") out = 1 - Math.pow(vals.A / vals.N, 1 / vals.n);
  if (op === "t") out = Math.log(vals.A / vals.N) / Math.log(1 - vals.i);

  const label = { a: "A", n: "N", dc: "Dc", i: "i", t: "n" }[op];
  const text = op === "i"
    ? `${label} = ${formats.num6(out)} (${formats.pct(out)})`
    : op === "t"
      ? `${label} = ${formats.num6(out)}`
      : `${label} = ${formats.money(out)}`;
  setResult(defs.dcc.result, text, false);
}

function calcDescRacional() {
  const op = document.getElementById(defs.drc.select).value;
  const vals = getValuesByWrap(defs.drc.fieldsWrap);
  if (!mustFinite(vals)) throw new Error("Preencha todos os campos numericos.");

  if ((op === "i" || op === "t") && vals.A === 0) throw new Error("A nao pode ser zero.");
  if ((op === "i" || op === "t") && vals.N <= 0) throw new Error("N deve ser maior que zero.");
  if (op === "i" && vals.n === 0) throw new Error("n nao pode ser zero.");
  if (op === "t" && vals.i === -1) throw new Error("i nao pode ser -1.");

  let out;
  if (op === "a") out = vals.N * Math.pow(1 + vals.i, -vals.n);
  if (op === "n") out = vals.A * Math.pow(1 + vals.i, vals.n);
  if (op === "dr") out = vals.N * (1 - Math.pow(1 + vals.i, -vals.n));
  if (op === "i") out = Math.pow(vals.N / vals.A, 1 / vals.n) - 1;
  if (op === "t") out = (Math.log(vals.N) - Math.log(vals.A)) / Math.log(1 + vals.i);

  const label = { a: "A", n: "N", dr: "Dr", i: "i", t: "n" }[op];
  const text = op === "i"
    ? `${label} = ${formats.num6(out)} (${formats.pct(out)})`
    : op === "t"
      ? `${label} = ${formats.num6(out)}`
      : `${label} = ${formats.money(out)}`;
  setResult(defs.drc.result, text, false);
}

function calcSac() {
  const op = document.getElementById(defs.sac.select).value;
  const vals = getValuesByWrap(defs.sac.fieldsWrap);
  if (!mustFinite(vals)) throw new Error("Preencha todos os campos numericos.");

  positive("n", vals.n);
  const amort = vals.VP / vals.n;
  let out;

  if (op === "amort") out = amort;
  if (op === "pmt") out = amort * (1 + (vals.n - vals.t + 1) * vals.i);
  if (op === "j") out = amort * (vals.n - vals.t + 1) * vals.i;
  if (op === "sd") out = vals.VP - amort * vals.t;

  const label = { amort: "Amortizacao", pmt: "PMT", j: "Juros", sd: "Saldo Devedor" }[op];
  setResult(defs.sac.result, `${label} = ${formats.money(out)}`, false);
}

function calcTaxas() {
  const op = document.getElementById(defs.te.select).value;
  const vals = getValuesByWrap(defs.te.fieldsWrap);
  if (!mustFinite(vals)) throw new Error("Preencha todos os campos numericos.");

  if ((op === "mm" || op === "mM") && vals.n === 0) throw new Error("n nao pode ser zero.");
  if (op === "ef" && vals.k === 0) throw new Error("k nao pode ser zero.");

  let out;
  if (op === "mm") out = Math.pow(1 + vals.ic, 1 / vals.n) - 1;
  if (op === "mM") out = Math.pow(1 + vals.ic, vals.n) - 1;
  if (op === "ef") out = vals.ik / vals.k;

  setResult(defs.te.result, `Nova taxa = ${formats.num6(out)} (${formats.pct(out)})`, false);
}

function calcFvp() {
  const n = Number(document.getElementById("fvp-n").value);
  const i = Number(document.getElementById("fvp-i").value);
  const vp = Number(document.getElementById("fvp-vp").value);
  const mult = Number(document.getElementById("fvp-mult").value);

  if (![n, i, vp, mult].every(Number.isFinite)) {
    throw new Error("Preencha todos os campos numericos.");
  }
  if (i === 0) throw new Error("Taxa i nao pode ser zero para esta formula.");

  const fvp = (1 - Math.pow(1 + i, -n)) / i;
  const pmt = vp * (1 / fvp);
  const resultado = fvp * mult;

  setResult(
    "fvp-result",
    `FVP = ${formats.num6(fvp)} | PMT = ${formats.num6(pmt)} | Resultado = ${formats.money(resultado)}`,
    false,
  );
}

function parseFluxos(raw) {
  const parts = raw
    .split(",")
    .map((x) => x.trim())
    .filter(Boolean)
    .map(Number);

  if (!parts.length || parts.some((v) => !Number.isFinite(v))) {
    throw new Error("Fluxos invalidos. Use numeros separados por virgula.");
  }
  return parts;
}

function calcVpl() {
  const I = Number(document.getElementById("vpl-i0").value);
  const i = Number(document.getElementById("vpl-i").value);
  const n = Number(document.getElementById("vpl-n").value);
  const fluxos = parseFluxos(document.getElementById("vpl-fluxos").value);
  const temVR = document.getElementById("vpl-tem-vr").checked;
  const vrInput = Number(document.getElementById("vpl-vr").value);
  const periodoVR = Number(document.getElementById("vpl-periodo-vr").value);

  if (![I, i, n].every(Number.isFinite)) throw new Error("Preencha I, i e n.");
  positive("n", n);
  if (i === -1) throw new Error("i nao pode ser -1.");
  if (fluxos.length !== n) throw new Error(`Foram informados ${fluxos.length} fluxos, mas n = ${n}.`);

  let vpl = 0;
  for (let j = 1; j <= n; j += 1) {
    vpl += fluxos[j - 1] / Math.pow(1 + i, j);
  }

  if (temVR) {
    if (![vrInput, periodoVR].every(Number.isFinite)) {
      throw new Error("Informe VR e periodo do VR.");
    }
    vpl += vrInput / Math.pow(1 + i, periodoVR);
  }

  vpl -= I;

  const parecer = vpl < 0 ? "VPL negativo: deve recusar." : "VPL positivo: deve aceitar.";
  setResult("vpl-result", `VPL = ${formats.money(vpl)} | ${parecer}`, false);
}

function setupVplResidualToggle() {
  const check = document.getElementById("vpl-tem-vr");
  const vr = document.getElementById("vpl-vr");
  const periodo = document.getElementById("vpl-periodo-vr");

  const sync = () => {
    vr.disabled = !check.checked;
    periodo.disabled = !check.checked;
  };

  check.addEventListener("change", sync);
  sync();
}

["js", "jc", "dcc", "drc", "sac", "te"].forEach(buildDynamicCalculator);
setupVplResidualToggle();
attachActions();
