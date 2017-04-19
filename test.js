function addLinks() {
    for (var i = 0, link; i < 5; i++) {
        link = document.createElement("a");
        link.innerHTML = "Link " + i;
        link.onclick = function() {
            alert(i);
        };
        document.body.appendChild(link);
    }
}