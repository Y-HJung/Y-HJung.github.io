let button = document.querySelector('.button');
let info = document.querySelector('.info');

button.onclick = function() {
  button.classList.toggle('active');
  info.classList.toggle('active');
}
