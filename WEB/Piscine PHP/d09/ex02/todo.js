    window.onload = function cookie() {
        var cookie;
        console.log(document.cookie);
        var cook = document.cookie.split(';');
        console.log(cook.length);
        if (cook.length > 0 && cook[0].length > 0) {
            cook.forEach(function(element) {
                cookie = element.split('=');
                addElement(cookie[1]);
            });      
        }
    }
    
    function supp(e) {
        var cook = e.target.id;
        var str = prompt("souhaitez-vous supprimer ce to do?");
        if (str == "oui") {
            var old = document.getElementById(cook);
            document.getElementById('ft_list').removeChild(old);
            document.cookie = cook+'='+cook+'; expires=Thu, 18 Dec 1903 12:00:00 UTC; path=/';
        }
    }
    
    function addElement(str) {
        var node = document.createElement("div");
		var textnode = document.createTextNode(str);
        node.appendChild(textnode);
        node.addEventListener('click', supp);
		node.id = str;
        var list = document.getElementById("ft_list");
		document.getElementById("ft_list").insertBefore(node, list.childNodes[0]);

	}

    function todo() {
        var str = prompt("to do or to dom ?");
        str = str.replace(';', ' ');
        str = str.replace('=', ' ');
        document.cookie = str+'='+str+'; expires=Thu, 18 Dec 2070 12:00:00 UTC; path=/';
        if (str)
            addElement(str);
    }