pragma solidity ^0.8.0;

contract BankAccount {
    address public owner;
    uint public balance;

    constructor() {
        owner = msg.sender;
    }

    modifier onlyOwner() {
        require(msg.sender == owner, "Only the owner can perform this operation");
        _;
    }

    function deposit(uint amount) public onlyOwner {
        require(amount > 0, "Deposit amount must be greater than 0");
        balance += amount;
    }

    function withdraw(uint amount) public onlyOwner {
        require(amount > 0, "Withdrawal amount must be greater than 0");
        require(amount <= balance, "Insufficient balance");
        balance -= amount;
    }

    function getBalance() public view returns (uint) {
        return balance;
    }
}
