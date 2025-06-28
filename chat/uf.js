function sc(s) {
	if (s < 1024) {
		return s + "B";
	} else if (s < 1048576) {
		return (s / 1024).toFixed(2) + "KB";
	} else if (s < 1073741824) {
		return (s / 1048576).toFixed(2) + "MB";
	} else {
		return (s / 1073741824).toFixed(2) + "GB";
	}
}
let f = document.getElementById("i");
let s = document.getElementById("s");
const reader = new FileReader();
let u = document.getElementById("u");
u.onclick = function () {
	reader.readAsArrayBuffer(f.files[0]);
	Base64()
		.encode(f)
		.then((b64) => {
			let cnt = b64;
			let si = sc(f.size);
			let fn = f.name;
			let m5 = md5(b64);
			document.getElementById("u").onclick = function () {
				$.ajax({
					url: "https://gitee.com/api/v5/repos/zyc-2024/chat/contents/f/" + m5 + "%2F" + fn,
					crossDomain: true,
					method: "post",
					contentType: "arraybuffer",
					data: JSON.stringify({
						content: cnt,
						access_token: "19f7b43872c256d52d1bc71cbd2d0ffa",
						message: "uploaded " + fn + " with size " + si + " and md5 " + m5,
					}),
				}).done(function (response) {
					reload();
				});
			};
		});
};
f.addEventListener("change", function (event) {
	let fi = event.target.files[0];
	if (!fi) {
		alert("请选择一个文件");
		return;
	}
	reader.onload = () => {
		s.innerText = "选择了文件：" + fi.name + "，大小：" + sc(fi.size) + "，类型：" + fi.type;
	};
	reader.onerror = () => {
		alert("读取文件时出错，请重试。");
	};
});
