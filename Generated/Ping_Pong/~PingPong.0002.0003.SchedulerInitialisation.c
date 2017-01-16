
#include "~PingPong.0000.0000.Header.h"


/* Domain Scheduler Initialisation */

void adm_scheduler_initialisation_pinger(
    void)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_INITIALISATION, "adm_scheduler_initialisation_pinger");
    #endif

    adm_dispatch_home_pool_ping();
    adm_dispatch_home_pool_pong();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_INITIALISATION, "adm_scheduler_initialisation_pinger");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */