<?php
    class  NightsWatch {
        public static $oui = "";

        public function recruit($charo) {
            NightsWatch::$oui = NightsWatch::$oui.";".get_class($charo);
        }
        public function fight() {
            $exp = explode(";", NightsWatch::$oui);
            foreach ($exp as $elem) {
                if ($elem == "JonSnow")
                    Jonsnow::fight();
                if ($elem == "SamwellTarly")
                    SamwellTarly::fight();
            }
        }
    }
?>