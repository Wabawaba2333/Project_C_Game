# ProjectGame
Project game
Källkodsstruktur
Luminewood/
├── CMakeLists.txt            /* Tre mål: client / server / test */
├── Makefile                  /* Wrapper för cmake: client / server / test / run-test / clean */
├── .gitattributes            /* * text=auto */
├── third/
│   ├── cute_tiled.h
│   ├── SDL2_net/             /* SDL2_net förkompilerat paket (Windows DLL + header-filer) */
│   └── SDL3/                 /* SDL3 + SDL3_ttf + SDL3_mixer förkompilerade paket */
├── assets/
│   ├── maps/
│   │   ├── test.tmx          /* Sprint 0 platshållarkarta för testning */
│   │   └── game.tmx          /* Sprint 4.5 officiell bana */
│   ├── sprites/              /* Alla sprite sheet PNG-filer */
│   ├── tiles/                /* Tileset PNG-filer */
│   ├── audio/                /* .wav-ljudfiler */
│   └── fonts/                /* .ttf-typsnittsfiler */
├── docs/
│   └── sprite_spec.md        /* Låses i Sprint 0, får inte ändras */
├── src/
│   ├── sim/                  /* ★ Rent logiklager – får absolut INTE #include:a några SDL-header-filer ★ */
│   │   ├── sim_constants.h   /* Globala numeriska konstanter (inga beroenden) */
│   │   ├── world.c/h
│   │   ├── physics.c/h
│   │   ├── player.c/h
│   │   ├── monster.c/h
│   │   ├── item.c/h
│   │   ├── daycycle.c/h
│   │   └── rules.c/h
│   ├── net/
│   │   └── protocol.h        /* Meddelandeenumeration + alla nätverksstrukturer (#pragma pack(push,1)) */
│   ├── client/
│   │   ├── main.c
│   │   ├── scene.c/h
│   │   ├── render.c/h
│   │   ├── camera.c/h
│   │   ├── animation.c/h
│   │   ├── hud.c/h
│   │   ├── audio.c/h
│   │   ├── input.c/h
│   │   ├── darkness.c/h      /* Innehåller #define HALO_RADIUS 400.0f */
│   │   └── net_client.c/h
│   └── server/
│       ├── main.c
│       └── net_server.c/h
└── tests/
    ├── test_rng.c
    ├── test_pool.c
    ├── test_monster_cap.c
    ├── test_damage.c
    ├── test_buff.c
    └── test_item_pickup.c

Del IV: Globala kodkonventioner (ska vara på plats vid slutet av Sprint 0)
4.1 sim_constants.h (enda platsen för konstanter)
Alla numeriska konstanter definieras en enda gång i src/sim/sim_constants.h. Både sim/ och net/ inkluderar den.
/* src/sim/sim_constants.h */
#pragma once

/* Spelare/spelskala */
#define MAX_PLAYERS              4
#define MAX_BUFFS                8
#define MAX_MONSTERS             256   /* Övre gräns för Pool */
#define MAX_SNAPSHOT_MONSTERS    95    /* Övre gräns för ögonblicksbildsöverföring: 95×12 + 180 + 23 = 1343 byte, godkänns av MTU-assert */
#define MAX_ITEMS                64    /* Övre gräns för ItemPool (server + klientens lokala tillstånd, ingår ej i ögonblicksbild) */
#define MAX_PATH_LEN             128   /* Längd på monsters vägbuffert */
#define MAX_TRAPS                8     /* Maximalt antal fallluckor i kartan */

/* Fysik */
#define GRAVITY                  1800.0f
#define FRICTION                 8.0f
#define PLAYER_SPEED             200.0f
#define JUMP_VELOCITY            (-600.0f)
#define LADDER_SPEED             150.0f
#define FALL_IMPULSE             600.0f   /* Nedåtimpuls vid stötback från falllucka */

/* Kamera */
#define DEADZONE_X               80.0f
#define DEADZONE_Y               60.0f
#define LERP_SPEED               5.0f

/* Batteri */
#define MAX_BATTERY              100.0f
#define DARKNESS_DAMAGE_PER_SEC  5.0f

/* Nätverk */
#define SERVER_TCP_PORT          2001
#define SERVER_UDP_PORT          7777
#define SNAPSHOT_INTERVAL_TICKS  3      /* 60Hz / 3 = 20Hz ögonblicksbilder */
#define MIN_PLAYERS              2      /* För testningsändamål: behöver inte vänta på 4 spelare */
#define PROTOCOL_VERSION         0x01

/* Vägfinnning */
#define PATHFIND_INTERVAL_TICKS  10

/* Övre gräns för spelackumulator (förhindrar dödsspiral) */
#define ACCUMULATOR_MAX          0.25f
