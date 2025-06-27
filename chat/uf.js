function uf(){
	window.scroll({
		top: document.body.scrollHeight,
		behavior: "smooth",
	});
	let cnt = Base64.encode(
		JSON.stringify({
			msg: [
				{
					name: namee,
					time: new Date().toISOString().replace("T", " ").replace("Z", "").split(".")[0].replaceAll("-", ""),
					content: "created " + ch,
				},
			],
		})
	);
	console.log("create");
	$.ajax({
		url: "https://gitee.com/api/v5/repos/zyc-2024/chat/contents/" + ch + ".json",
		crossDomain: true,
		method: "post",
		contentType: "arraybuffer",
		data: JSON.stringify({
			content: cnt,
			access_token: "19f7b43872c256d52d1bc71cbd2d0ffa",
			message: "uploaded "+na+" with size "+si+" and md5 "+m5,
		}),
	}).done(function (response) {
		reload();
	});
};