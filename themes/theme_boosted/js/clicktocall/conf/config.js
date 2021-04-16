let c2c_serverConfig = {
    domain: 'ccpaas.orange-business.ru', // AudioCodes SBC domain name, used to build SIP headers From/To
    addresses: ['wss://sbc.ccpaas.orange-business.ru'], // AudioCodes SBC secure web socket address (can be multiple)
    //iceServers: ['74.125.140.127:19302', '74.125.143.127:19302'] // addresses for STUN servers.
};

let c2c_config = {
    call: '5000', // Call to this user name (or phone number).
    caller: 'call_from_website', // Caller user name (One word according SIP RFC 3261). 
    callerDN: 'click2call', // Caller display name (words sequence).
    messageDisplayTime: 5, // A message will be displayed during this time (seconds).
    restoreCallMaxDelay: 20 // After page reloading, call can be restored within the time interval (seconds).
};