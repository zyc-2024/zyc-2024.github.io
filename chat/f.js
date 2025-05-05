var eee;
function upload(
	ucontent = '{"msg":[{"name":"zyc2024","time":"20250504","content":"test3"},{"name":"zyc2024","time":"20250505","content":"test4mc"}]}'
) {
	var sha;
	$.ajax({
		url: "https://gitee.com/api/v5/repos/zyc-2024/chat/raw/data.json",
		crossDomain: true,
		contentType: "application/json;charset=UTF-8",
		data: {
			access_token: "19f7b43872c256d52d1bc71cbd2d0ffa",
		},
	}).done(function (response) {
		// console.log("GETDATA FUNCTION\n" + JSON.stringify(response) + "\n\n");
		// console.log("PARAMS\n" + name + "\n" + time + "\n" + content);
		r = JSON.parse(response);
		r.msg[r.msg.length] = {
			name: $("input.name")[0].value,
			time: $("input.time")[0].value,
			content: $("input.content")[0].value,
		};
		$.get("https://gitee.com/api/v5/repos/zyc-2024/chat/contents/data.json", {
			access_token: "19f7b43872c256d52d1bc71cbd2d0ffa",
		}).done(function (response) {
			// console.log("GETSHA SUCCESS\n", response, "\n\n");
			// console.log(response);
			eee = response.sha;
			sha = response.sha; var t = new Date();
			// var ok = 0;
			$.ajax({
				url: "https://gitee.com/api/v5/repos/zyc-2024/chat/contents/data.json",
				crossDomain: true,
				method: "PUT",
				contentType: "application/json;charset=UTF-8",
				data: JSON.stringify({
					access_token: "19f7b43872c256d52d1bc71cbd2d0ffa",
					content: Base64.encode(JSON.stringify(r)),
					sha: sha,
					message: $("input.name")[0].value + " @ " + t.getTime(),
				}),
				success: function (response) {
					// console.log("UPLOAD SUCCESS\n" + JSON.stringify(response) + "\n\n");
				},
				error: function (xhr, status, error) {
					// console.log("UPLOAD ERROR\n" + JSON.stringify(xhr) + "\n" + status + "\n" + error);
					// console.log("Request body:", JSON.stringify({
						// access_token: "19f7b43872c256d52d1bc71cbd2d0ffa",
						// content: Base64.encode(ucontent),
						// sha: sha,
						// message: $("input.name")[0].value + " @ " + t.getTime(),
					// }));
				},
			}).done(function (response) {
				// ok = 1;
				// console.log("UPLOAD FUNCTION\n" + JSON.stringify(response) + "\n\n");
				// console.log(ucontent + "\n" + Base64.encode(ucontent) + "\n" + sha);

				reload();
			});
		}).fail(function (xhr, status, error) {
			// console.log("GETSHA ERROR\n", xhr, "\n" + status + "\n" + error);
		});
	});

}
var rrrr;
function reload() {
	var content;
	$.ajax({
		url: "https://gitee.com/api/v5/repos/zyc-2024/chat/raw/data.json",
		crossDomain: true,
		contentType: "application/json;charset=UTF-8",
		data: {
			access_token: "19f7b43872c256d52d1bc71cbd2d0ffa",
		},
	}).done(function (response) {
		// console.log("RELOAD FUNCTION\n" ,JSON.stringify(response),"\n\n");
		// console.log(response);console.dir(response);
		content = rrrr=JSON.parse(response);
		document.getElementById("chat").innerHTML = "";
		if (content.msg) {
			var msg = content.msg;
			// 处理 msg
		} else {
			console.error("response 中没有 msg 属性");
			var msg=[];
		}
		for (let i in msg) {
			document.getElementById("chat").innerHTML +=
				"<tr><td>" +
				msg[i].name +
				"</td><td>" +
				msg[i].time +
				"</td><td>" +
				msg[i].content +
				"</td></tr>";
		}
	});
}

reload();

//chatkey 19f7b43872c256d52d1bc71cbd2d0ffa
//samples {"msg":[{"name":"zyc2024","time":"20250504","content":"test3"},{"name":"zyc2024","time":"20250505","content":"test4mc"}]}
