#include <stdint.h>
#define TAILLE 19

uint64_t zobrist_table[TAILLE][TAILLE][2];
uint64_t seed = 123465789ULL;
uint64_t game_state;
uint64_t turn_token;
uint64_t game_history[1024];
int total_moves = 0;

// for random generation i will use SplitMix64
uint64_t rand64(uint64_t *state) {
    uint64_t z = (*state += 0x9E3779B97F4A7C15ULL);
    z = (z ^ (z >> 30)) * 0xBF58476D1CE4E5B9ULL;
    z = (z ^ (z >> 27)) * 0x94D049BB133111EBULL;
    return z ^ (z >> 31);
}

void init_zobrist() {
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            for (int k = 0; k < 2; k++) {
                zobrist_table[i][j][k] = rand64(&seed);
            }
        }
    }
    turn_token = rand64(&seed);
    game_state = rand64(&seed);
}

void add_stone(int ligne, int colonne, int joueurActuel) {
    game_state ^= zobrist_table[ligne][colonne][joueurActuel];
}

void remove_stone(int ligne, int colonne, int stoneColor) {
    game_state ^= zobrist_table[ligne][colonne][stoneColor];
}

void swap_turn() {
    game_state ^= turn_token;
}

void save_state() {
    game_history[total_moves] = game_state;
}

int check_ko() {
    for (int i = 0; i < total_moves; i++) {
        if (game_state == game_history[i]) {
            return 1;
        }
    }
    save_state();
    return 0;
}
