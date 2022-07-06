constexpr const char* mqtt_broker = "192.168.1.20";
constexpr const char* topic = "lightBoard/test";
constexpr int mqtt_port = 1883;

constexpr const char* channel0_config = "homeassistant/light/salon/config";
constexpr const char* channel0_command = "homeassistant/light/salon/set";
constexpr const char* channel0_state = "homeassistant/light/salon/state";
const char* channel0_config_body = "\
{\
  \"~\": \"homeassistant/light/salon\",\
  \"name\": \"salon\",\
  \"unique_id\": \"salon_light\",\
  \"cmd_t\": \"~/set\",\
  \"stat_t\": \"~/state\",\
  \"brightness\": false\
}";

constexpr const char* channel1_config = "homeassistant/light/sypialnia/config";
constexpr const char* channel1_command = "homeassistant/light/sypialnia/set";
constexpr const char* channel1_state = "homeassistant/light/sypialnia/state";
const char* channel1_config_body = "\
{\
  \"~\": \"homeassistant/light/sypialnia\",\
  \"name\": \"sypialnia\",\
  \"unique_id\": \"sypialnia_light\",\
  \"cmd_t\": \"~/set\",\
  \"stat_t\": \"~/state\",\
  \"brightness\": false\
}";

constexpr const char* channel2_config = "homeassistant/light/garderoba/config";
constexpr const char* channel2_command = "homeassistant/light/garderoba/set";
constexpr const char* channel2_state = "homeassistant/light/garderoba/state";
const char* channel2_config_body = "\
{\
  \"~\": \"homeassistant/light/garderoba\",\
  \"name\": \"garderoba\",\
  \"unique_id\": \"garderoba_light\",\
  \"cmd_t\": \"~/set\",\
  \"stat_t\": \"~/state\",\
  \"brightness\": false\
}";

constexpr const char* channel3_config = "homeassistant/light/lazienka/config";
constexpr const char* channel3_command = "homeassistant/light/lazienka/set";
constexpr const char* channel3_state = "homeassistant/light/lazienka/state";
const char* channel3_config_body = "\
{\
  \"~\": \"homeassistant/light/lazienka\",\
  \"name\": \"lazienka\",\
  \"unique_id\": \"lazienka_light\",\
  \"cmd_t\": \"~/set\",\
  \"stat_t\": \"~/state\",\
  \"brightness\": false\
}";

constexpr const char* channel4_config = "homeassistant/light/kinkiety/config";
constexpr const char* channel4_command = "homeassistant/light/kinkiety/set";
constexpr const char* channel4_state = "homeassistant/light/kinkiety/state";
const char* channel4_config_body = "\
{\
  \"~\": \"homeassistant/light/kinkiety\",\
  \"name\": \"kinkiety\",\
  \"unique_id\": \"kinkiety_light\",\
  \"cmd_t\": \"~/set\",\
  \"stat_t\": \"~/state\",\
  \"brightness\": false\
}";

constexpr const char* channel5_config = "homeassistant/light/wentylator/config";
constexpr const char* channel5_command = "homeassistant/light/wentylator/set";
constexpr const char* channel5_state = "homeassistant/light/wentylator/state";
const char* channel5_config_body = "\
{\
  \"~\": \"homeassistant/light/wentylator\",\
  \"name\": \"wentylator\",\
  \"unique_id\": \"wentylator_light\",\
  \"cmd_t\": \"~/set\",\
  \"stat_t\": \"~/state\",\
  \"brightness\": false\
}";

constexpr const char* channel6_config = "homeassistant/light/przedpokoj/config";
constexpr const char* channel6_command = "homeassistant/light/przedpokoj/set";
constexpr const char* channel6_state = "homeassistant/light/przedpokoj/state";
const char* channel6_config_body = "\
{\
  \"~\": \"homeassistant/light/przedpokoj\",\
  \"name\": \"przedpokoj\",\
  \"unique_id\": \"przedpokoj_light\",\
  \"cmd_t\": \"~/set\",\
  \"stat_t\": \"~/state\",\
  \"brightness\": false\
}";

