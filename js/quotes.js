let quotes = ["welcome"];
addEventListener("DOMContentLoaded", function () {
	let quote = document.getElementById("quotes");
	let random = Math.floor(Math.random() * quotes.length);
	quote.innerHTML = quotes[random];
});
