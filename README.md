# RISC-V-5grade

关于Hazard：必定是影响比自己滞后的，不可能影响先于自己的
第一种：EX、1类数据冒险：lui的rd，auipc的rd，addi、slti、sltiu、xori、ori、andi、slli、srli、srai、add、sub、sll、slt、sltu、xor、srl、sra、or、and的rd，与第二级所有含有rs1 或 rs2的操作发生冲突。方法：在一轮操作完成第一级流水刚刚完成ex（逆序由下向上）时进行检查，若冲突，则把ex_result的imme放入registor的reg[rs1]或[rs2]。

第二种：MEM、2类数据冒险：与一类数据冒险冲突情况相同。方法：在一轮操作完成第一级流水刚刚完成mem时对第三级进行检查，若冲突，去检查第二级的rd是否是冲突点，若是则跳过，若不是，则把mem_result的imme放入registor的reg[rs1]或[rs2].

第三种：Load-use冒险，取数使用冒险。要求第一级流水的mem完成后，才能进行下一级的ex。冲突情况：L型的rd与所有含有rs1或rs2的操作发生冲突。方法：涉及三级流水，需要及时发现并且将后两级流水延迟，第二级完成了decode之后进行冲突判断，若不冲突则不变，若冲突，记录此时registor的状态于缓存并打上标记，见标记的操作为空一轮，同时下一轮的IF停止，在下一轮开始时把缓存补回。由于涉及两轮，需要合理设置flag。

第四种：分支冒险



