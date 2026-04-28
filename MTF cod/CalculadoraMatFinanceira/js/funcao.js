
function AbrirDivJurosSimples() {
    document.getElementById('DivJurosSimples').style.display = "block";
    document.getElementById('DivJurosCompostos').style.display = "none";
}
function AbrirDivJurosCompostos() {
    document.getElementById('DivJurosCompostos').style.display = "block";
    document.getElementById('DivJurosSimples').style.display = "none";
}

function Calc_VF() {
    let vp = document.getElementById("VF_vp").value;
    let i = document.getElementById("VF_i").value / 100;
    let n = document.getElementById("VF_n").value;

   
        document.getElementById("VF_vf").value = (vp * (1 + i * n)).toFixed(2);
    
}

function Calc_VJ1() {

    // valor_dos_juros:
    

    let vf = document.getElementById("VJ_vf").value; // Valor Futuro

    let vp = document.getElementById("VJ_vp").value; // Valor presente


    let j = 0;

        j = vf - vp;

        document.getElementById("Vj_vj1").value = j.toFixed(2);
   
    
}

function Calc_VJ2(){


    let vp2 = document.getElementById("VJ_vp2").value; // Valor presente

    let i = document.getElementById("VJ_i").value / 100; // Taxa

    let n = document.getElementById("VJ_t").value; // Tempo
    console.log(i);


        document.getElementById("Vj_vj2").value = (vp2 * i * n).toFixed(2);
    
}

function Calc_VP1(){

    let vf = document.getElementById("VP_vf").value;

    let i = document.getElementById("VP_i").value / 100;

    let n = document.getElementById("VP_n").value;
    
    document.getElementById("VP_vp1").value = (vf / (1 + (i * n))).toFixed(2);  

}

function Calc_VP2() {

    let j = document.getElementById("VP_vj").value;

    let i  = document.getElementById("VP_i2").value / 100;

    let n = document.getElementById("VP_t").value;

    
    document.getElementById("VP_vp2").value = ( j / (i * n)).toFixed(2);  
}

function Calc_Taxa1(){

    let vf = document.getElementById("I_vf").value;

    let vp = document.getElementById("I_vp").value;

    let n = document.getElementById("I_n").value;

    

     document.getElementById("I_i1").value = (( ((vf / vp) - 1) / n)*100).toFixed(2);  

    

}

function Calc_Taxa2() {

    
    let j = document.getElementById("I_j").value;

    let vp = document.getElementById("I_vp").value;

    let n = document.getElementById("I_n").value;

    document.getElementById("I_i2").value = ((  i = j / (vp * n) *100)).toFixed(2); 
}

function Calc_Tempo1() {

    let vf = document.getElementById("T_vf").value;

    let vp = document.getElementById("T_vp1").value;

    let i = document.getElementById("T_i").value / 100;


     document.getElementById("T_t1").value = (((vf / vp) -1) / i).toFixed(2);

}

function Calc_Tempo2(){


    let j = document.getElementById("T_j").value;

    let vp = document.getElementById("T_vp2").value;

    let i = document.getElementById("T_i2").value;


    document.getElementById("T_t2").value = ((j / (vp * i)) * 100).toFixed(2);

}
