operators = ['+', '-', '*', '//']

vals = {}
# for operator in operators:
#     exp = "4 {} 4".format(operator)
#     result = str(eval(exp))
#     equ = "{} = {}".format(exp.replace('//', '/'), result)
#     vals[result] = equ

# for op_1 in operators:
#     for op_2 in operators:
#         exp = "4 {} 4 {} 4".format(op_1, op_2)
#         result = str(eval(exp))
#         equ = "{} = {}".format(exp.replace('//', '/'), result)
#         vals[result] = equ

for op_1 in operators:
    for op_2 in operators:
        for op_3 in operators:
            exp = "4 {} 4 {} 4 {} 4".format(op_1, op_2, op_3)
            result = str(eval(exp))
            equ = "{} = {}".format(exp.replace('//', '/'), result)
            vals[result] = equ

print(vals)