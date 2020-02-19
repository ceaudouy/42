<?php
    class UnholyFactory {
        public static $alr_ab = "";
        public static $class = "";
        private $check;
        private $new;
        public function absorb($ab) {
            $check = explode(";", UnholyFactory::$class);
            $check = array_filter($check, 'strlen');
            $a = in_array(get_class($ab), $check);
            if (!empty($a)) {
                print ("(Factory already absorbed a fighter of type ".$ab->get_name().")\n");
            }
            else {
                if (method_exists($ab, '__construct')) {
                    UnholyFactory::$alr_ab = UnholyFactory::$alr_ab.";".$ab->get_name();
                    UnholyFactory::$class = UnholyFactory::$class.";".get_class($ab);
                    print ("(Factory absorbed a fighter of type ".$ab->get_name().")\n");
                }
                else {
                    print ("(Factory can't absorb this, it's not a fighter)\n");
                }
            }
        }

        public function fabricate($rf) {
            $check = explode(";", UnholyFactory::$class);
            $name = explode(";", UnholyFactory::$alr_ab);
            $check = array_filter($check, 'strlen');
            $name = array_filter($name, 'strlen');
            $a = array_search($rf, $name);
            if (!empty($a)) {
                print ("(Factory fabricates a fighter of type ".$rf.")\n");
                return (new $check[$a]);
            }
            else {
                print ("(Factory hasn't absorbed any fighter of type ".$rf.")\n");
            }
        }
    }
?>
