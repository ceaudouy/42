<?php
    class Tyrion extends Lannister {
        public function sleepwith($oui) {
            if ($oui instanceof Jaime)
                print ("Not even if I'm drunk !\n");   
            if ($oui instanceof Sansa) 
            print ("Let's do this.\n");
            if ($oui instanceof Cersei)
                print ("Not even if I'm drunk !\n");   
        }
    }
?>