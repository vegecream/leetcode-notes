"""
CleanRL DQN 简单示例
基于CleanRL的DQN算法实现
"""

import gymnasium as gym
import numpy as np
import torch
import torch.nn as nn
import torch.optim as optim

class QNetwork(nn.Module):
    """Q网络"""
    def __init__(self, obs_space, action_space):
        super().__init__()
        self.network = nn.Sequential(
            nn.Linear(np.array(obs_space.shape).prod(), 120),
            nn.ReLU(),
            nn.Linear(120, 84),
            nn.ReLU(),
            nn.Linear(84, action_space.n),
        )

    def forward(self, x):
        return self.network(x)

def train_dqn():
    """训练DQN智能体"""
    env = gym.make("CartPole-v1")
    q_network = QNetwork(env.observation_space, env.action_space)
    optimizer = optim.Adam(q_network.parameters(), lr=2.5e-4)
    
    # 训练循环
    for episode in range(100):
        obs, _ = env.reset()
        done = False
        total_reward = 0
        
        while not done:
            # 选择动作
            with torch.no_grad():
                q_values = q_network(torch.Tensor(obs))
                action = torch.argmax(q_values).item()
            
            # 执行动作
            next_obs, reward, terminated, truncated, _ = env.step(action)
            done = terminated or truncated
            total_reward += reward
            obs = next_obs
        
        print(f"Episode {episode}, Total Reward: {total_reward}")
    
    env.close()

if __name__ == "__main__":
    train_dqn()
