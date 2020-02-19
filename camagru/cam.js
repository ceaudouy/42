var video = document.querySelector("#video");
	canvas = document.getElementById('canvas');
	context = canvas.getContext('2d');
	c = document.getElementById("filtre");
	cadre_select = "none";
	picture = 0;

if (navigator.mediaDevices.getUserMedia) {
	navigator.mediaDevices.getUserMedia({ video: true }).then(function(stream){
		video.srcObject = stream;
	})
	.catch(function(err0r) {
		console.log("Something went wrong !");
	})
}

document.getElementById('capture').addEventListener('click', function(){
	if (cadre_select == "none")
	{
		alert ("Selectionnez un cadre en premier !");
		return ;
	}
	context.drawImage(video, 0, 0, 400, 300);
	var img = document.getElementById(cadre_select);
	context.drawImage(img, 0, 0, 400, 300);
	picture = 1;
});


function reply_click(clicked_id){
	cadre_select = clicked_id;
	var c = document.getElementById("filtre");
	var ctx = c.getContext('2d');
	var img = document.getElementById(cadre_select);
	context.clearRect(0, 0, 400, 300);
	ctx.clearRect(0, 0, 400, 300);
	ctx.drawImage(img, 0, 0, 400, 300);
	context.drawImage(img, 0, 0, 400, 300);
}

document.getElementById("submit").onclick = function(e) {

	var check_canv = canvas.toDataURL();
	var check_c = c.toDataURL();

	if (check_canv.length != 0 && check_c.length != 0 && picture === 1)
	{
		picture = 0;
		var img_save = canvas.toDataURL();
		document.getElementById("base64").value = img_save;
	}
	else
		alert("Veuillez selectionner un cadre puis prendre une photo");
}

var image = document.getElementById('image');
    image.addEventListener('change', affiche, false);
function affiche(e){
  if (cadre_select === "none") {
          alert("Selectionnez un cadre avant de choisir une image");
          document.getElementById('image').value = "";
          return(0);
        }
    var reader = new FileReader();
    reader.onload = function(event){
        var img = new Image();
        var cadre = document.getElementById(cadre_select);
        img.onload = function(){
            context.drawImage(img,0, 0, 400, 300);
			context.drawImage(cadre, 0, 0, 400, 300);
			picture = 1;
        }
        img.src = event.target.result;
    }
    reader.readAsDataURL(e.target.files[0]);     
}