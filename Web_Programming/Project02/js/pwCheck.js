let inputPw = document.getElementById('pw_check');
let msgPw = document.querySelector('.pw_error');
let btn = document.querySelector('.btn');
let show = document.getElementById('show');

let idDel = document.querySelector('div[class$=delBtn]');

inputPw.onkeyup = function() {
  if(inputPw.value != "") {
    idDel.style.visibility = "visible";
  }
  else {
    idDel.style.visibility = "hidden";
  }
}
idDel.onclick = function() {
  inputPw.value = "";
  idDel.style.visibility = "hidden";
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
  if (inputPw.value != "") {
    btn.type ="submit";
  }
  else if(inputPw.value == "") {
    msgPw.style.display = "block";
    document.querySelector('.login').style.height = "330px";
    inputPw.focus();
  }
}
