const id = document.getElementById('id_input')
const pw = document.getElementById('pw_input');
const pwCheck = document.getElementById('pwCheck_input');
const name = document.getElementById('name_input');
const gender = document.getElementById('gender_sel');
const tel = document.getElementById('tel_input');
const btn = document.querySelector('.btn');

const show = document.querySelectorAll('i[class^=far]');
const pwError = document.querySelector('.pw_error');
const error = document.querySelectorAll('.error');

let b_Error = [true, true, true, true, true, true];
let b_PwErr = true;

id.onblur = function() {
  if(id.value === "") {
    error[0].style.display ="block";
    b_Error[0] = true;
  }
}
id.onkeyup = function() {
  if(id.value === "") {
    error[0].style.display ="block";
    b_Error[0] = true;
  }
  else {
    error[0].style.display = "none";
    b_Error[0] = false;
  }
}

pw.onblur = function() {
  if(pw.value === "") {
    error[1].style.display ="block";
    b_Error[1] = true;
  }
}
pw.onkeyup = function() {
  if(pw.value === "") {
    error[1].style.display ="block";
    b_Error[1] = true;
  }
  else {
    error[1].style.display = "none";
    b_Error[1] = false;
  }
  if(pw.value === pwCheck.value) {
    pwError.style.display = "none";
    b_PwErr = false;
	pwCheck.disabled = true;
  } 
  else {
    pwError.style.display = "block";
    b_PwErr = true;
	pwCheck.disabled = false;
  }
}

pwCheck.onblur = function() {
  if(pw.value !== pwCheck.value) {
    pwError.style.display = "block";
    b_PwErr = true;
  }
  else {
    pwError.style.display = "none";
    b_PwErr = false;
  }
  if(pwCheck.value === "") {
    error[2].style.display = "block";
    b_Error[2] = true;
  }
}
pwCheck.addEventListener('keyup', function(e) {
  if(e.key !== 'Backspace') {
    pwError.style.display = "none";
    b_PwErr = false;
  }
  error[2].style.display = "none";
  b_Error[2] = false;
  if(pwCheck.value === "") {
    error[2].style.display = "block";
    b_Error[2] = true;
  }
  else {
    error[2].style.display = "none";
    b_Error[2] = false;
  }
  if(pw.value === pwCheck.value) {
    pwError.style.display = "none";
    b_PwErr = false;
	pwCheck.disabled = true;
  } 
  else {
    pwError.style.display = "block";
    b_PwErr = true;
  }
});

name.onblur = function() {
  if(name.value === "") {
    error[3].style.display ="block";
    b_Error[3] = true;
  }
}
name.onkeyup = function() {
  if(name.value === "") {
    error[3].style.display ="block";
    b_Error[3] = true;
  }
  else {
    error[3].style.display = "none";
    b_Error[3] = false;
  }
}

gender.onclick = function() {
  if(gender.options[gender.selectedIndex].value == "M" || gender.options[gender.selectedIndex].value == "F") {
    b_Error[4] = false;
    error[4].style.display = "none";
  } else {
    b_Error[4] = true;
  }
}


tel.onblur = function() {
  if(tel.value === "") {
    error[5].style.display ="block";
    b_Error[5] = true;
  }
}
tel.onkeyup = function() {
  if(tel.value === "") {
    error[5].style.display ="block";
    b_Error[5] = true;
  }
  else {
    error[5].style.display = "none";
    b_Error[5] = false;
  }
}

show[0].onclick = function() {
  if(pw.type == "password") {
    pw.type = "text";
    show[0].className = "far fa-eye";
  }
  else if(pw.type == "text") {
    pw.type = "password";
    show[0].className = "far fa-eye-slash";
  }
}
show[1].onclick = function() {
  if(pwCheck.type == "password") {
    pwCheck.type = "text";
    show[1].className = "far fa-eye";
  }
  else if(pwCheck.type == "text") {
    pwCheck.type = "password";
    show[1].className = "far fa-eye-slash";
  }
}

btn.onclick = function() {
  if(b_Error[0] == false && b_Error[1] == false && b_Error[2] == false && b_Error[3] == false && b_Error[4] == false && b_Error[5] == false && b_PwErr == false) {
    btn.type = "submit";
  }
  else {
    for(let i=0; i<b_Error.length; i++) {
      if(b_Error[i] == true) error[i].style.display = "block";
    }
  }
}
