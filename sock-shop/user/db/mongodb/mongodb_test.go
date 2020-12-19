/*
 * MIT License
 *
 * Copyright (c) 2020 manager
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

package mongodb

import (
	"fmt"
	"os"
	"testing"

	"github.com/usmanager/microservices/sock-shop/user/users"
	"gopkg.in/mgo.v2/bson"
	"gopkg.in/mgo.v2/dbtest"
)

var (
	TestMongo  = Mongo{}
	TestServer = dbtest.DBServer{}
	TestUser   = users.User{
		FirstName: "firstname",
		LastName:  "lastname",
		Username:  "username",
		Password:  "blahblah",
		Addresses: []users.Address{
			users.Address{
				Street: "street",
			},
		},
	}
)

func init() {
	TestServer.SetPath("/tmp")
}

func TestMain(m *testing.M) {
	TestMongo.Session = TestServer.Session()
	TestMongo.EnsureIndexes()
	TestMongo.Session.Close()
	exitTest(m.Run())
}

func exitTest(i int) {
	TestServer.Wipe()
	TestServer.Stop()
	os.Exit(i)
}

func TestInit(t *testing.T) {
	err := TestMongo.Init()
	if err.Error() != "no reachable servers" {
		t.Error("expecting no reachable servers error")
	}
}

func TestNew(t *testing.T) {
	m := New()
	if m.AddressIDs == nil || m.CardIDs == nil {
		t.Error("Expected non nil arrays")
	}
}

func TestAddUserIDs(t *testing.T) {
	m := New()
	uid := bson.NewObjectId()
	cid := bson.NewObjectId()
	aid := bson.NewObjectId()
	m.ID = uid
	m.AddressIDs = append(m.AddressIDs, aid)
	m.CardIDs = append(m.CardIDs, cid)
	m.AddUserIDs()
	if len(m.Addresses) != 1 && len(m.Cards) != 1 {
		t.Error(
			fmt.Sprintf(
				"Expected one card and one address added."))
	}
	if m.Addresses[0].ID != aid.Hex() {
		t.Error("Expected matching Address Hex")
	}
	if m.Cards[0].ID != cid.Hex() {
		t.Error("Expected matching Card Hex")
	}
	if m.UserID != uid.Hex() {
		t.Error("Expected matching User Hex")
	}
}

func TestAddressAddId(t *testing.T) {
	m := MongoAddress{Address: users.Address{}}
	id := bson.NewObjectId()
	m.ID = id
	m.AddID()
	if m.Address.ID != id.Hex() {
		t.Error("Expected matching Address Hex")
	}
}

func TestCardAddId(t *testing.T) {
	m := MongoCard{Card: users.Card{}}
	id := bson.NewObjectId()
	m.ID = id
	m.AddID()
	if m.Card.ID != id.Hex() {
		t.Error("Expected matching Card Hex")
	}
}

func TestCreate(t *testing.T) {
	TestMongo.Session = TestServer.Session()
	defer TestMongo.Session.Close()
	err := TestMongo.CreateUser(&TestUser)
	if err != nil {
		t.Error(err)
	}
	err = TestMongo.CreateUser(&TestUser)
	if err == nil {
		t.Error("Expected duplicate key error")
	}
}

func TestGetUserByName(t *testing.T) {
	TestMongo.Session = TestServer.Session()
	defer TestMongo.Session.Close()
	u, err := TestMongo.GetUserByName(TestUser.Username)
	if err != nil {
		t.Error(err)
	}
	if u.Username != TestUser.Username {
		t.Error("expected equal usernames")
	}
	_, err = TestMongo.GetUserByName("bogususers")
	if err == nil {
		t.Error("expected not found error")
	}
}

func TestGetUser(t *testing.T) {
	TestMongo.Session = TestServer.Session()
	defer TestMongo.Session.Close()
	_, err := TestMongo.GetUser(TestUser.UserID)
	if err != nil {
		t.Error(err)
	}
}

func TestGetUserAttributes(t *testing.T) {
	TestMongo.Session = TestServer.Session()
	defer TestMongo.Session.Close()

}
func TestGetURL(t *testing.T) {
	name = "test"
	password = "password"
	host = "thishostshouldnotexist:3038"
	u := getURL()
	if u.String() != "mongodb://test:password@thishostshouldnotexist:3038/users" {
		t.Error("expected url mismatch")
	}
}

func TestPing(t *testing.T) {
	TestMongo.Session = TestServer.Session()
	defer TestMongo.Session.Close()
	err := TestMongo.Ping()
	if err != nil {
		t.Error(err)
	}
}
