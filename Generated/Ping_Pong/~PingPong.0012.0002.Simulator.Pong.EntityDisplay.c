
#include "~PingPong.0000.0000.Header.h"


/* Pong Simulator Display Entity */

void adm_sim_display_entity_pong(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_pong_typ * ent_pong;

    adm_sim_width_pong_typ width_pong;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_pong");
    #endif

    width_pong.identity = strlen("Identity");
    width_pong.status = strlen("Status");

    ent_pong = adm_entity_system.ent_pong.live_list_head;

    while (ent_pong != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_pong->identity);
        if (width > width_pong.identity) width_pong.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%s", adm_sim_status_pong[ent_pong->status]);
        if (width > width_pong.status) width_pong.status = width;

        ent_pong = ent_pong->next;
    }

    printf(NEWLINE);
    printf("Pong:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_pong.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_pong.status, "Status");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_pong.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_pong.status);

    ent_pong = adm_entity_system.ent_pong.live_list_head;

    while (ent_pong != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_pong.identity, ent_pong->identity);
        printf(ADM_SIM_COLUMN_GAP);

        switch (ent_pong->status) {
            case ADM_STATUS_PONG_ACTIVATE :
                printf("%-*s", width_pong.status, "Activate");
            break;
            case ADM_STATUS_PONG_SENDING :
                printf("%-*s", width_pong.status, "Sending");
            break;
            case ADM_STATUS_PONG_WAITING :
                printf("%-*s", width_pong.status, "Waiting");
            break;
            case ADM_STATUS_PONG_TERMINATED :
                printf("%-*s", width_pong.status, "Terminated");
            break;
            default :
                printf("%-*s", width_pong.status, "ERROR");
            break;
        }


        ent_pong = ent_pong->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_pong");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */