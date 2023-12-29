class KnowledgeBase:
    def __init__(self):
        self.facts = set()

    def add_fact(self, fact):
        self.facts.add(fact)

    def check_entailment(self, statement):
        return all(rule(statement) for rule in self.facts)

# Corrected rules
def rule_0(statement):
    return "p" in statement.lower()

def rule_1(statement):
    return "~p" in statement.lower() or "q" in statement.lower()

def rule_2(statement):
    return "p" in statement.lower() or "~q" in statement.lower()

def rule_3(statement):
    return "p" in statement.lower() or "~q" in statement.lower() or "r" in statement.lower()

def rule_4(statement):
    return "~q" in statement.lower() or "r" in statement.lower()

# Example usage
kb = KnowledgeBase()
kb.add_fact(rule_0)
kb.add_fact(rule_1)
kb.add_fact(rule_2)
kb.add_fact(rule_3)
kb.add_fact(rule_4)

user_statement = input("Enter a statement: ")
entailment_result = kb.check_entailment(user_statement)

if entailment_result:
    print("The statement is entailed by the knowledge base.")
else:
    print("The statement is not entailed by the knowledge base.")
