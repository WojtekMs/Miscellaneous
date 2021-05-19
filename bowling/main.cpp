SCENARIO("player should receive points")
{
  GIVEN("10 frames of game passed") {
      auto originalScore = player.getScore();
      player.makeMove();  
      WHEN("player knocked down 5 bowls") {
          player.knockDownBowls(5);
          THEN("player should receive 10 points") {
              REQUIRE(player.getScore() == originalScore + 10);
          }
      }
  }
}
