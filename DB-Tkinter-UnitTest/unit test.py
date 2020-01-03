import unittest
import LinkGame


class MyTestCase(unittest.TestCase):
    def testDataBase(self):
        LinkGame.Database()
        LinkGame.insert_player('ssssss','1234','5')
        self.assertTrue(LinkGame.IsExist('ssssss','1234'))
    def testadmin(self):
        LinkGame.Database()
        LinkGame.insert_admin('iiiiii', '1234', '5')
        self.assertTrue(LinkGame.CheckIsAdmin('iiiiii'))
    def testdeletPlayer(self):
        LinkGame.Database()
        LinkGame.deletePlayer('ssssss')
        self.assertTrue(LinkGame.IsExist('ssssss', '1234'))
    def testAge(self):
        self.assertTrue(LinkGame.checkAge(5))
if __name__ == '__main__':
    unittest.main()
