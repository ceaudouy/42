<?php
    class Fighter {

       private $_name;

        public function __construct($type) {
            $this->_name = $type;
            return;
        }
        public function get_name() {
            return $this->_name;
        }
    }
?>