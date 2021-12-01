let inputId = document.getElementById('id_check');
let inputPw = document.getElementById('pw_check');
let msgId = document.querySelector('.id_error');
let msgPw = document.querySelector('.pw_error');
let btn = document.querySelector('.btn');
let show = document.getElementById('show');

let idDel = document.querySelectorAll('div[class$=delBtn]');

inputId.onkeyup = function() {
  if (inputId.value != "") {
    idDel[0].style.visibility = "visible";
  }
  else {
    idDel[0].style.visibility = "hidden";
  }
}
idDel[0].onclick = function() {
  inputId.value = "";
  idDel[0].style.visibility = "hidden";
}

inputPw.onkeyup = function() {
  if(inputPw.value != "") {
    idDel[1].style.visibility = "visible";
  }
  else {
    idDel[1].style.visibility = "hidden";
  }
}
idDel[1].onclick = function() {
  inputPw.value = "";
  idDel[1].style.visibility = "hidden";
}

show.onclick = function() {
  if(show.checked == true) {
    inputPw.type = "text";
  }
  else {
    inputPw.type = "password";
  }
}

btn.onclick = function() {
  if (inputId.value != "" && inputPw.value != "") {
    btn.type ="submit";
  }
  else if(inputId.value == "") {
    msgId.style.display = "block";
    msgPw.style.display = "none";
    document.querySelector('.login').style.height = "330px";
    inputId.focus();
  }
  else if(inputId.value != "" && inputPw.value == "") {
    msgId.style.display = "none";
    msgPw.style.display = "block";
    document.querySelector('.login').style.height = "330px";
    inputPw.focus();
  }
}
