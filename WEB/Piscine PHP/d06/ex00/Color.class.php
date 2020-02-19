<?php

Class Color {
    
    public $red;
    public $green;
    public $blue;
    public $rgb;
    public static $verbose = FALSE;
    
    public static function doc(){
        return file_get_contents("Color.doc.txt");
    }

    public function __construct( array $couleur ) {
        
        if (isset($couleur['rgb']) AND !empty($couleur['rgb']))
        {
            $red = intval(($couleur['rgb'] >> 16) & 255);
            $green = intval(($couleur['rgb'] >> 8) & 255);
            $blue = intval($couleur['rgb'] & 255);
        }
        else 
        {
            $red  = intval($couleur['red']);
            $green = intval($couleur['green']);
            $blue = intval($couleur['blue']);
        }
        $this->red = $red;
        $this->green = $green;
        $this->blue = $blue;
        if (Self::$verbose == TRUE)
        {
            printf("Color( red: %3d, green: %3d, blue: %3d ) constructed.\n", $this->red, $this->green, $this->blue);
        }
        return ;
    }

    public function __ToString () {
        return (vsprintf("Color( red: %3d, green: %3d, blue: %3d )", array($this->red, $this->green, $this->blue)));
    }

    public function add($couleur) {
        return new Color(array ('red' => $this->red + $couleur->red, 'green' => $this->green + $couleur->green, 'blue' => $this->blue + $couleur->blue));
    }

    public function sub($couleur) {
        return new Color(array ('red' => $this->red - $couleur->red, 'green' => $this->green - $couleur->green, 'blue' => $this->blue - $couleur->blue));
    }

    public function mult($couleur) {
        return new Color(array ('red' => $this->red * $couleur, 'green' => $this->green * $couleur, 'blue' => $this->blue * $couleur));
    }
    function __destruct() {
        if (Self::$verbose == TRUE)
        {
            printf("Color( red: %3d, green: %3d, blue: %3d ) destructed.\n", $this->red, $this->green, $this->blue);
        return ;	
        }
	}
}
?>