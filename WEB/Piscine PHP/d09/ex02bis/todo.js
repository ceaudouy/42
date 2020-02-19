    window.onload = function cookie() {
        var cookie;
        var cook = document.cookie.split(';');
        if (cook.length > 0 && cook[0].length > 0) {
            cook.forEach(function(element) {
                cookie = element.split('=');
                addElement(cookie[1]);
            });      
        }
    }
    
    function addElement(str) {
        $("#ft_list").prepend("<p id='"+str+"'>"+str+"</p>");
		var elem = $("#ft_list").find("p");
        $(elem[0]).bind('click', function() {
			var conf = prompt("Voulez-vous vraiment le supprimer ?");
			if (conf == 'oui') {
                this.remove();
                document.cookie = str+'='+str+'; expires=Thu, 18 Dec 1903 12:00:00 UTC; path=/';
          	}
		});
	}

    function todo() {
        var str = prompt("to do or to dom ?");
        str = str.replace(';', ' ');
        str = str.replace('=', ' ');
        document.cookie = str+'='+str+'; expires=Thu, 18 Dec 2070 12:00:00 UTC; path=/';
        if (str)
            addElement(str);
    }