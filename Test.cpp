//
// Created by Ginton on 24/05/2020.
//
#include "doctest.h"
#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"



namespace WarGame {
    WarGame::Board board(8, 8);
    TEST_CASE ("FootCommander VS FootCommander") {

                CHECK(!board.has_soldiers(1));
        board[{5, 3}] = new FootCommander(1);
                CHECK(board.has_soldiers(1));

                CHECK(!board.has_soldiers(2));
        board[{5, 7}] = new FootCommander(2);
                CHECK(board.has_soldiers(2));
        CHECK_THROWS(board.move(1, {5, 7}, WarGame::Board::MoveDIR::Up));
        CHECK_THROWS(board.move(2, {5, 7}, WarGame::Board::MoveDIR::Down));
                CHECK(board.has_soldiers(1));
                CHECK(board.has_soldiers(2));
    }

    TEST_CASE ("FootSoldier VS FootCommander") {
        WarGame::Board board(8, 8);
                CHECK(!board.has_soldiers(1));
        board[{3, 6}] = new FootSoldier(1);
        CHECK_THROWS((board[{3, 6}] = new FootSoldier(1)));
        board[{5, 3}] = new FootCommander(1);
        board[{6, 1}] = new FootSoldier(1);
                CHECK(board.has_soldiers(1));
                CHECK(!board.has_soldiers(2));
        for (int i = 0; i < 20; i++) {
                    CHECK(board.has_soldiers(2));
        }
    }

    TEST_CASE ("FootSoldier VS FootSoldier") {
        WarGame::Board board(8, 8);
                CHECK(!board.has_soldiers(1));
        board[{3, 6}] = new FootSoldier(1);
        CHECK_THROWS((board[{3, 6}] = new FootSoldier(1)));
        board[{5, 3}] = new FootSoldier(1);
        board[{6, 1}] = new FootSoldier(1);
                CHECK(board.has_soldiers(1));
        for (int i = 0; i < 8; i++) {
            board[{i, i}] = new FootSoldier(1);
                    CHECK(board.has_soldiers(1));
                    CHECK(!board.has_soldiers(2));
        }
                CHECK(!board.has_soldiers(2));
    }

    TEST_CASE ("Sniper VS Sniper") {
        WarGame::Board board(8, 8);
                CHECK(!board.has_soldiers(1));
        board[{3, 6}] = new FootSoldier(1);
        CHECK_THROWS((board[{3, 6}] = new Sniper(1)));
        board[{5, 3}] = new Sniper(1);
        board[{6, 1}] = new Sniper(1);
                CHECK(board.has_soldiers(1));
        for (int i = 0; i < 8; i++) {
            board[{i, i}] = new Sniper(1);
                    CHECK(board.has_soldiers(1));
                    CHECK(!board.has_soldiers(2));
        }
                CHECK(!board.has_soldiers(2));
    }
    TEST_CASE ("SniperCommander VS SniperCommander") {
        WarGame::Board board(8, 8);
                CHECK(!board.has_soldiers(1));
        board[{3, 6}] = new FootSoldier(1);
        CHECK_THROWS((board[{3, 6}] = new SniperCommander(1)));
        board[{5, 3}] = new SniperCommander(1);
        board[{6, 1}] = new SniperCommander(1);
                CHECK(board.has_soldiers(1));
        for (int i = 0; i < 8; i++) {
            board[{i, i}] = new Sniper(1);
                    CHECK(board.has_soldiers(1));
                    CHECK(!board.has_soldiers(2));
        }
                CHECK(!board.has_soldiers(2));
    }

    TEST_CASE (" moves outside") {
                CHECK(!board.has_soldiers(1));
        board[{5, 1}] = new FootSoldier(1);
        CHECK_THROWS(board.move(1, {6, 1}, WarGame::Board::MoveDIR::Up)); //no soldier their
                CHECK(!board.has_soldiers(2));
        board[{5, 4}] = new FootSoldier(2);
        CHECK_THROWS(board.move(2, {3, 1}, WarGame::Board::MoveDIR::Up)); //no soldier their
        board[{5, 1}] = new FootSoldier(1);
        board[{7, 1}] = new FootSoldier(1);
        CHECK_THROWS(board.move(1, {7, 1}, WarGame::Board::MoveDIR::Up)); //outside
        board[{0, 1}] = new FootSoldier(1);
        CHECK_THROWS(board.move(1, {7, 1}, WarGame::Board::MoveDIR::Down)); //outside
        board[{0, 7}] = new FootSoldier(2);
        CHECK_THROWS(board.move(2, {0, 7}, WarGame::Board::MoveDIR::Right)); //outside
        board[{0, 0}] = new FootSoldier(2);

        CHECK_THROWS(board.move(2, {0, 7}, WarGame::Board::MoveDIR::Left)); //outside
    }

    TEST_CASE ("init") {
        for (int i = 0; i < 8; i++) {
            board[{i, i}] = new FootCommander(1);
                    CHECK(board.has_soldiers(1));
                    CHECK(!board.has_soldiers(2));
        }
    }

}
