function sc(s) {
	if (s < 1024) {
		return s + "B";
	} else if (s < 1048576) {
		return (s / 1024).toFixed(2) + "KB";
	} else {
		return (s / 1048576).toFixed(2) + "MB";
	}
}
let f = document.getElementById("i");
let s = document.getElementById("s");
let u = document.getElementById("u");
function uf() {
	let file = f.files[0];
	if (file) {
		s.innerHTML = "选择了：" + file.name + "（" + sc(file.size) + "）";
	} else {
		s.innerHTML = "你选了个寂寞a";
	}
}
